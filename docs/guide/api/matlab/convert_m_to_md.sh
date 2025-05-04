#!/bin/bash

# Usage: ./convert_m_to_md.sh input_folder output_folder
# easiest to navigate to this folder and type for eg: ./convert_m_to_md.sh ../../../../src/gauss_quadrature_rules/ .

input_folder="$1"
output_folder="$2"
blank_template="blank.md"
yaml_output="${output_folder}/files.yaml"

# Check if input and output folders are provided
if [[ -z "$input_folder" || -z "$output_folder" ]]; then
  echo "Usage: $0 input_folder output_folder"
  exit 1
fi

# Check if blank.md exists
if [[ ! -f "$blank_template" ]]; then
  echo "Error: $blank_template not found in the current directory."
  exit 1
fi

# Create output folder if it doesn't exist
mkdir -p "$output_folder"

# Start the YAML file
echo "files:" > "$yaml_output"

# Iterate over .m files
for file in "$input_folder"/*.m; do
  if [[ -f "$file" ]]; then
    base_name=$(basename "$file" .m)
    new_file="${base_name}.md"
    new_path="${output_folder}/${new_file}"

    # If file doesn't exist, create it
    if [[ -f "$new_path" ]]; then
      echo "Skipping $new_file (already exists)"
    else
      cp "$blank_template" "$new_path"
      echo "Created $new_file"
    fi

    # Add to YAML list (whether newly created or skipped)
    echo "  - $new_file" >> "$yaml_output"
  fi
done

echo "Done! All .md files listed in $yaml_output"
