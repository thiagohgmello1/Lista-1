%%
clear all;
clc;

fileID1 = fopen('superior.txt','r');
fileID2 = fopen('b1.txt','r');

row1 = fscanf(fileID1, ['row: ' '%f']);
fgetl(fileID1);
column1 = fscanf(fileID1, ['column: ' '%f']);
fgetl(fileID1);
size = fscanf(fileID2, ['size: ' '%f']);
fgetl(fileID2);

sizeM = [column1 row1];
sizeA = size;
formatSpec1 = "";
formatSpec2 = "%f";

for i=1:column1
    formatSpec1 = formatSpec1 + "%f ";
end

A = fscanf(fileID1, formatSpec1, sizeM);
A = A';
% A = log10(pi.^A);

b = fscanf(fileID2, formatSpec2, sizeA);

x = linsolve(A,b);

norma = norm(x);
norma_str = sprintf("%0.23f", norma);

fclose(fileID1);
fclose(fileID2);

%%

fileID1 = fopen('inferior.txt','r');
fileID2 = fopen('b2.txt','r');

row1 = fscanf(fileID1, ['row: ' '%f']);
fgetl(fileID1);
column1 = fscanf(fileID1, ['column: ' '%f']);
fgetl(fileID1);
size = fscanf(fileID2, ['size: ' '%f']);
fgetl(fileID2);

sizeM = [column1 row1];
sizeA = size;
formatSpec1 = "";
formatSpec2 = "%f";

for i=1:column1
    formatSpec1 = formatSpec1 + "%f ";
end

A = fscanf(fileID1, formatSpec1, sizeM);
A = A';
% A = log10(pi.^A);

b = fscanf(fileID2, formatSpec2, sizeA);

x = linsolve(A,b);

norma = norm(x);
norma_str = sprintf("%0.23f", norma);

fclose(fileID1);
fclose(fileID2);







