clc;
cd ..;
addPaths();
cd testSweet;
files = dir;
tests = [];
m = 0;

%collect all .m files in this folder which aren't this one:
for n = 1:length(files)
    if length(files(n).name)>1
        if strcmp(files(n).name([(end-1):end]),'.m') && ~strcmp(files(n).name,'testAll.m')
            m = m + 1;
            tests{m} = files(n).name([1:(end-2)]);
        end
    end
end

%now run each test file:
m=0;
for m = 1 : length(tests)
    try
        passTest(m) = eval(tests{m});
    catch
        fprintf('\nerror in %s',tests{m});
        passTest(m) = false;
    end
    if passTest(m)
        disp('...passed');
    else
        disp('...failed');
    end
    fprintf('\n');
end

if min(passTest)
    disp('All tests passed');
else
    disp('At least one test failed');
end