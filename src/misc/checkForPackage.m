function isIncluded = checkForPackage(packageName)
% checks if a particular package is installed 
    packages = ver;
    isIncluded = false;
    for ip = packages
        % check if name of element matches desired package
        if strcmp(ip.Name, packageName)
            isIncluded = true;
            break;
        end
    end
end