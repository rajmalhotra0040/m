clc; clear; close all;

% ----- Input Section -----
x = input('Enter the number of symbols: ');
N = 1:x;  % Symbol set (1 to x)
disp('The number of symbols are N:');
disp(N);

p = input('Enter the probabilities as a vector: ');  % Input probabilities
if abs(sum(p) - 1) > 1e-6
    error('Probabilities must sum to 1');
end
disp('The input probabilities are:');
disp(p);

% ----- Sorting -----
[s, idx] = sort(p, 'descend');   % Sort probabilities in descending order
symbols_sorted = N(idx);
disp('The sorted probabilities are:');
disp(s);

% ----- Huffman Dictionary -----
[dict, avglen] = huffmandict(symbols_sorted, s);
disp('Huffman Dictionary (Symbol : Codeword):');
disp(dict);
disp('The average length of code is:');
disp(avglen);

% ----- Entropy Calculation -----
H = -sum(p .* log2(p));   % Entropy formula
disp('Entropy is:');
disp(H);
disp('bits/msg');

% ----- Efficiency -----
E = (H / avglen) * 100;
disp('Efficiency is:');
disp(E);

% ----- Encoding -----
sequence = symbols_sorted;  % Example sequence
codeword = huffmanenco(sequence, dict);
disp('Encoded Codeword:');
disp(codeword);

% ----- Decoding -----
decoded = huffmandeco(codeword, dict);
disp('Decoded Output:');
disp(decoded);
