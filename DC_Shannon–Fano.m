clc;
clear all;

% Given symbols and probabilities
symbols = {'X1','X2','X3','X4','X5'};
p = [0.46 0.15 0.13 0.11 0.05];

% Sort in descending order
[p, idx] = sort(p, 'descend');
symbols = symbols(idx);

% Shannon–Fano coding
codes = shannon_fano(p);

% Display results
disp('Symbol    Probability    Code');
for i = 1:length(symbols)
    fprintf('%s\t\t%.2f\t\t%s\n', symbols{i}, p(i), codes{i});
end

% Entropy and efficiency
H = -sum(p .* log2(p));
Lavg = sum(p .* cellfun(@length, codes));
E = (H / Lavg) * 100;

fprintf('\nEntropy (H): %.4f bits/symbol\n', H);
fprintf('Average Code Length (Lavg): %.4f bits/symbol\n', Lavg);
fprintf('Efficiency: %.2f%%\n', E);

% --- Shannon–Fano Function ---
function codes = shannon_fano(p)
    n = length(p);
    codes = cell(1, n);
    assign_code(1, n, '');
    function assign_code(lo, hi, prefix)
        if lo == hi
            codes{lo} = prefix;
            return;
        end
        total = sum(p(lo:hi));
        cum = cumsum(p(lo:hi));
        split = find(cum >= total/2, 1);
        split = lo + split - 1;
        assign_code(lo, split, [prefix '0']);
        assign_code(split+1, hi, [prefix '1']);
    end
end
