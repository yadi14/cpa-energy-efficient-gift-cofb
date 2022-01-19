%% for Gift SBOX
summarize = [];
foldername = "./Q1Q2Q3_simplfy/";
strname = [];% keep track of all the filenames
for i = 0:14
    for j = i+1:15
        for m = j+1:15
            filename = string(i)+"_"+j+"_"+m+".txt";
            strname = [strname;filename];
            S = readlines(foldername+filename);
            S(S=="") = [];
            %% Unique values in array with unique()
            S_2col = split(S);
            [U,ia,ic]=  unique(S_2col,'rows');
            length = size(U,1);
            % if length==16, it means that we can uniquely determine the
            % correct key cell with this file's (w/ file name = filname)
            % {q,q',q''} pair
            % if length!=16, meaning key cell may not uniquely identifies
            % through the correct {q,q',q''} pair
            summarize = [summarize;length];
            
        end
    end
end
%% list all the filename [q]_[q']_[q''].txt whose {q,q',q''} pair can uniquely determine 4-bit key cell
idx = 1:size(summarize,1);
max(summarize,[],'all')%16
distinguishingQpair = strname(summarize == max(summarize,[],'all'))
% dump the list of filename into a log file
writematrix(distinguishingQpair,"summaryList.log",'QuoteStrings',false,'FileType','text')
%% count how many of such {q,q',q''} pair which could drive key cell value
% == 416
numel(distinguishingQpair)
