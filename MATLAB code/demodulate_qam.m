function [out] = demodulate_qam(sig)
n = length(sig);
out = zeros(n,6);
a = zeros(1,6);

for i =1:n
    
    switch real(sig(i))
        case -7
            a(1:3)=[0 0 0];
        case -5
            a(1:3)=[0 0 1];
        case -3
            a(1:3)=[0 1 1];
        case -1
            a(1:3)=[0 1 0];
        case 1
            a(1:3)=[1 1 0];
        case 3
            a(1:3)=[1 0 0];
        case 5
            a(1:3)=[1 0 1];
        case 7
            a(1:3)=[1 1 1];
        
    end
    switch imag(sig(i))
        case -7
            a(4:6)=[0 0 0];
        case -5
            a(4:6)=[0 0 1];
        case -3
            a(4:6)=[0 1 1];
        case -1
            a(4:6)=[0 1 0];
        case 1
            a(4:6)=[1 1 0];
        case 3
            a(4:6)=[1 0 0];
        case 5
            a(4:6)=[1 0 1];
        case 7
            a(4:6)=[1 1 1];
        
    end
    
    out(i,:) = a;
end

end

