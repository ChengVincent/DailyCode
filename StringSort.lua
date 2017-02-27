--按照自己方法按key排序，打印key和value

function StringSort(stringTable) --len sort
	local temp={}
	i=0
	for key,_ in pairs(stringTable) do
		i=i+1
        temp[i]=key
    end


    table.sort(temp,function (key1,key2)
    	return string.len(key1) < string.len(key2)
    end)

    for i=1,(#temp) do
    	print("[" .. temp[i] .. "] = " .. stringTable[temp[i]])
    end
end


testTable={
	["lilei"] = 23,
	["chaozhou"] = 45,
	["lihuwang"] = 33,
    ["lileifjaslfjl"] = 23,
	["chaozhu"] = 45,
	["lihuwng"] = 33,
}

StringSort(testTable)

