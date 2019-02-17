aerotab = {'cyb' 'cnb' 'clq' 'cmq'};

for k = 1:length(aerotab)
    for m = 1:datcom{3}.nmach
        for h = 1:datcom{3}.nalt
            datcom{3}.(aerotab{k})(:,m,h) = datcom{3}.(aerotab{k})(1,m,h);
        end
    end
end