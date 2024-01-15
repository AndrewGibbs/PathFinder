function log_struct = initLog(filename)
    if nargin == 0
        filename = ['log',datestr(now, 0),'.txt'];
    end
    s = what('PathFinder');
    log_path = [s.path '/log/'];

    fid = fopen(fullfile(log_path, filename), 'w');
    fprintf(fid, 'PathFinder log, %s\n',datestr(now, 0));
    fclose(fid);

    log_struct = struct('path',log_path,'filename',filename,...
                         'take',true,'add_to_log',@(s) add_to_log(s,log_path,filename));

    function add_to_log(s,log_path_,filename_)
        fid_ = fopen(fullfile(log_path_, filename_), 'a');
        fprintf(fid_, '\n%s',s);
        fclose(fid_);
    end
end