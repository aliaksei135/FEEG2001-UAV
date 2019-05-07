file = fopen('G:\HEXLOG');
line = fgetl(file);
data = zeros(1, 14);
while line ~= -1
    numval = numel(line)/8;
    if(mod(numval, 1) ~= 0)
        error('Incomplete sample')
        continue;
    end
    row = zeros(1, numval);
    for k=0:numval-1
        num = line((8*k)+1:(8*k)+8);
        row(k+1) = hexsingle2num(num);
    end
    data = [data;row];
    line = fgetl(file);
end