clc;
clear all;
close all;

%% Linear Block Code (7,4)
% n = 7 → codeword length
% k = 4 → message length

n = 7;
k = 4;

% Generator matrix G (given in your question)
genmat = [1 0 0 0 1 1 0;
          0 1 0 0 1 1 1;
          0 0 1 0 1 1 1;
          0 0 0 1 1 0 1];

disp('Generator Matrix (G) = ');
disp(genmat);

% Example messages (each row = one message)
msg = [0 0 0 0;
       1 0 0 0;
       0 0 1 0;
       0 0 0 1];

disp('Input Messages:');
disp(msg);

%% Encoding the messages
code = encode(msg, n, k, 'linear', genmat);

disp('Encoded Codewords:');
disp(code);

%% Create Parity-Check Matrix (H)
parmat = gen2par(genmat);
disp('Parity-Check Matrix (H) = ');
disp(parmat);

%% Generate syndrome table (error vector table)
evt = syndtable(parmat); % built-in function
disp('Error Vector Table (syndrome lookup):');
disp(evt);

%% Suppose this is the received vector (with 1-bit error)
received = [0 0 0 1 1 0 0];
disp('Received Vector (with error):');
disp(received);

%% Compute the syndrome
syndrome = rem(received * parmat', 2); % mod-2 multiplication
syndrome_de = bi2de(syndrome, 'left-msb'); % convert binary → decimal
disp(['Syndrome (binary): ', num2str(syndrome), ...
      ' | Decimal: ', num2str(syndrome_de)]);

%% Find correction vector using error table
correct = evt(1 + syndrome_de, :);
disp('Correction Vector:');
disp(correct);

%% Correct the received codeword
corrected_code = rem(received + correct, 2);
disp('Corrected Codeword:');
disp(corrected_code);
