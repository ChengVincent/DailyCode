--打印一个菱形
function PrintIcon(starNum,spaceNum)
	local cow=""
	for i=1,starNum do
		cow = cow .. "*"
	end
		for j=1,spaceNum do
		cow = cow .. " "
	end
		for k=1,starNum do
		cow = cow .. "*"
	end
	print(cow)
end


function CaclIcon()
    for i=5,1,-1 do
    	if i==5 then
    		print("*********")
    	else
    		PrintIcon(i,9-2*i)
    	end
    end
    for j=2,5 do
    	if j==5 then
            print("*********")
        else
            PrintIcon(j,9-j*2)
        end
    end   
end

CaclIcon()