% -----------------------------------------------------------
% Program: Huffman Source Coding Method
% Author : Pushkar Waghela
% -----------------------------------------------------------
clc;
clear all;
close all;

% ----- Step 1: Define Symbols and Probabilities -----
Symbols = [1 2 3 4];
P = [0.1 0.3 0.4 0.2];   % Probabilities must sum to 1

% ----- Step 2: Generate Huffman Dictionary -----
dict = huffmandict(Symbols, P);

% Display Dictionary
disp('Huffman Dictionary (Symbol : Codeword)');
for i = 1:length(dict)
    fprintf('Symbol %d : %s\n', dict{i,1}, num2str(dict{i,2}));
end

% ----- Step 3: Encode and Decode -----
sig = Symbols;                       % Example sequence
hcode = huffmanenco(sig, dict);      % Encode
dhsig = huffmandeco(hcode, dict);    % Decode

% Display Results
disp(' ');
disp('Encoded Huffman Code:');
disp(hcode);
disp('Decoded Symbols:');
disp(dhsig);

% ----- Step 4: Entropy, Average Length & Efficiency -----
H = -sum(P .* log2(P));                        % Entropy
avglen = sum(P .* cellfun(@length, dict(:,2)));% Average code length
Eff = (H / avglen) * 100;                      % Efficiency

disp(' ');
fprintf('Entropy (H)           = %.4f bits/msg\n', H);
fprintf('Average Code Length   = %.4f bits/msg\n', avglen);
fprintf('Coding Efficiency     = %.2f %%\n', Eff);
