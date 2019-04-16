function [out] = modulate_qam(dec)

n = length(dec);
out = zeros(n,1);
for i =1:n
    a = 0+ 1j*0;
    if(bi2de(dec(i,1:3),'left-msb')==0)
        a=a+ -7;
    elseif(bi2de(dec(i,1:3),'left-msb')==1)
             a=a+ -5;
    elseif(bi2de(dec(i,1:3),'left-msb')==3)
             a=a+ -3;
    elseif(bi2de(dec(i,1:3),'left-msb')==2)
             a=a+ -1;
    elseif(bi2de(dec(i,1:3),'left-msb')==6)
             a=a+ 1;
    elseif(bi2de(dec(i,1:3),'left-msb')==4)
             a=a+ 3;
    elseif(bi2de(dec(i,1:3),'left-msb')==5)
             a=a+ 5;
    elseif(bi2de(dec(i,1:3),'left-msb')==7)
             a=a+ 7;   
                    
    end
    
    
    if(bi2de(dec(i,4:6),'left-msb')==0)
        a=a+ -1j*7;
    elseif(bi2de(dec(i,4:6),'left-msb')==1)
             a=a+ -1j*5;
    elseif(bi2de(dec(i,4:6),'left-msb')==3)
             a=a+ -1j*3;
    elseif(bi2de(dec(i,4:6),'left-msb')==2)
             a=a+ -1j*1;
    elseif(bi2de(dec(i,4:6),'left-msb')==6)
             a=a+ 1j*1;
    elseif(bi2de(dec(i,4:6),'left-msb')==4)
             a=a+ 1j*3;
    elseif(bi2de(dec(i,4:6),'left-msb')==5)
             a=a+ 1j*5;
    elseif(bi2de(dec(i,4:6),'left-msb')==7)
             a=a+ 1j*7; 
    end
    out(i) = a;
end

end

