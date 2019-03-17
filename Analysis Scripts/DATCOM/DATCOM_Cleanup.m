aerotab = {'cyb' 'cnb' 'clq' 'cmq'};
for n = 1:length(datcom)
    for k = 1:length(aerotab)
        for m = 1:datcom{n}.nmach
            for h = 1:datcom{n}.nalt
                datcom{n}.(aerotab{k})(:,m,h) = datcom{n}.(aerotab{k})(1,m,h);
                datcom{n}.('cnb')(:,m,h) = 3.032e-3;
            end
        end
    end
end