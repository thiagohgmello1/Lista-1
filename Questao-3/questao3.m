%%
clear all;
clc;

fpA = fopen('A.txt','r');
fpA1 = fopen('A1.txt','r');
fpA2 = fopen('A2.txt','r');

fpb = fopen('b.txt','r');
fpb1 = fopen('b1.txt','r');
fpb2 = fopen('b2.txt','r');

row = fscanf(fpA, ['row: ' '%f']);
fgetl(fpA);
column = fscanf(fpA, ['column: ' '%f']);
fgetl(fpA);
fgetl(fpA1);
fgetl(fpA1);
fgetl(fpA2);
fgetl(fpA2);
size = fscanf(fpb, ['size: ' '%f']);
fgetl(fpb);
fgetl(fpb1);
fgetl(fpb2);

sizeM = [column row];
sizeA = size;
formatSpec = "";

for i=1:column
    formatSpec = formatSpec + "%f ";
end

A = fscanf(fpA, formatSpec, sizeM);
A = A';
A1 = fscanf(fpA1, formatSpec, sizeM);
A1 = A1';
A2 = fscanf(fpA2, formatSpec, sizeM);
A2 = A2';

b = fscanf(fpb, formatSpec, sizeA);
b1 = fscanf(fpb1, formatSpec, sizeA);
b2 = fscanf(fpb2, formatSpec, sizeA);

fclose(fpA);
fclose(fpA1);
fclose(fpA2);
fclose(fpb);
fclose(fpb1);
fclose(fpb2);

x = linsolve(A,b);
x1 = linsolve(A1,b1);
x2 = linsolve(A2,b2);

norma = norm(x);
norma1 = norm(x1);
norma2 = norm(x2);







