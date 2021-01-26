%%
clear all;
clc;

fileID1 = fopen('M1.txt','r');
fileID2 = fopen('M2.txt','r');

row1 = fscanf(fileID1, ['row: ' '%f']);
fgetl(fileID1);
column1 = fscanf(fileID1, ['column: ' '%f']);
fgetl(fileID1);
row2 = fscanf(fileID2, ['row: ' '%f']);
fgetl(fileID2);
column2 = fscanf(fileID2, ['column: ' '%f']);
fgetl(fileID2);

sizeM1 = [column1 row1];
sizeM2 = [column2 row2];
formatSpec1 = "";
formatSpec2 = "";

for i=1:column1
    formatSpec1 = formatSpec1 + "%f ";
end
    
for i=1:column2
    formatSpec2 = formatSpec2 + "%f ";
end

M1 = fscanf(fileID1, formatSpec1, sizeM1);
M1 = M1';
M1 = log10(pi.^M1);

M2 = fscanf(fileID2, formatSpec2, sizeM2);
M2 = M2';
M2 = log10(pi.^M2);

M = M1*M2;

norma = norm(M,'fro');
norma_str = sprintf("%0.23f", norma);

fclose(fileID1);
fclose(fileID2);




