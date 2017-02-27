--公倍数，和公约数

function Gcd(num1, num2)
	if num1 < num2 then 
		do return Gcd(num2,num1) end
	elseif num2 == 0 then 
		do return num1 end
	else 
		return Gcd(num2, num1 % num2)
	end
end

function Lun(num1, num2)
	return num1*num2/Gcd(num1, num2)
end


print("the gdc is " .. Gcd(7,3))
print("the lun is " .. Lun(7,3))