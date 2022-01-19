%% for Gift SBOX
% check the multiple occurance of unique element in each .txt file,
% duplication should be at least twice.
foldername = "./Q1Q2_simplfy/";
strname = [];% keep track of all the filenames
for i = 0:14
    for j = i+1:15
        filename = string(i)+"_"+j+".txt";
        strname = [strname;filename];
        S = readlines(foldername+filename);
        S(S=="") = [];
        %% Unique values in array with unique()
        [U,iv1,iv2] = unique(S);
        % Count of Unique Elements in S
        a_counts = accumarray(iv2,1);
        % the multiple occurance of unique element should  be at least 2
        occurance = a_counts>=2;
        if (nnz(occurance)~=numel(a_counts))
            display(filename)
        end
        assert(nnz(occurance)==numel(a_counts)) % display Assertion failed, if not satisfied
    end
end