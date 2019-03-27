close all;
clear all;

n= [10000, 50000, 100000, 500000, 1000000];

fileID= fopen("0.txt", "r");
A= fscanf(fileID, "%i");
semilogx(n, A, '-x');
grid on;
hold on;

fileID= fopen("250.txt", "r");
A= fscanf(fileID, "%i");
semilogx(n, A, '-x');

fileID= fopen("500.txt", "r");
A= fscanf(fileID, "%i");
semilogx(n, A, '-x');

fileID= fopen("750.txt", "r");
A= fscanf(fileID, "%i");
semilogx(n, A, '-x');

fileID= fopen("1000.txt", "r");
A= fscanf(fileID, "%i");
semilogx(n, A, '-x');

xlabel("Wielkość problemu (N)");
ylabel("Czas");
title("Wykres 1");