--fibonacci兔子问题
function Rabbit(month)
    if month == 1 or month == 2 then
    	do return 1 end
    else
        return Rabbit(month-1)+Rabbit(month-2)
    end	
end

print(Rabbit(2))