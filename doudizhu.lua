-- 请根据上家每种出牌牌型编写程序，输出大于其对应的可能牌型

yourCard = {"J",6,2,8,10,8,"K","J",9,9,8,"J",9,7,6,"J","Q",7,10,10} --自己的牌
OPCard = {
	{5},
	{3,3},
	{3,3,3},
	{3,3,3,2},
	{3,4,5,6,7},
	{4,4,4,5,5},
	{3,3,4,4,5,5},
	{3,3,3,4,4,4,5,5,5},
	{3,3,3,3,4,4},
	{3,3,3,3}
}

card_details = { 
    [1]=0,
    [2]=0,
    [3]=0,
    [4]=0,
    [5]=0,
    [6]=0,
    [7]=0,
    [8]=0,
    [9]=0,
    [10]=0,
    [11]=0,
    [12]=0,
    [13]=0,
    [14]=1,
    [15]=1
} --记录牌各自数量

card_show ={
    [1]=3,
    [2]=4,
    [3]=5,
    [4]=6,
    [5]=7,
    [6]=8,
    [7]=9,
    [8]=10,
    [9]="J",
    [10]="Q",
    [11]="K",
    [12]=1,
    [13]=2,
    [14]="*",
    [15]="$"	
}--展示牌中内容

card_show_index={
    [3]=1,
    [4]=2,
    [5]=3,
    [6]=4,
    [7]=5,
    [8]=6,
    [9]=7,
    [10]=8,
    ["J"]=9,
    ["Q"]=10,
    ["K"]=11,
    [1]=12,
    [2]=13,
    ["*"]=14,
    ["$"]=15	
}--展示每张牌对应下表

--[[
函数：AddDetails
参数：无
意义：处理手中的牌，看每种牌有几张，加入到card_details表中
--]]
function AddDetails()  
	for i in pairs(yourCard) do
        if yourCard[i] == "J" then
        	card_details[9]=card_details[9]+1
        elseif yourCard[i] == "Q" then
            card_details[10]=card_details[10]+1
        elseif yourCard[i]=="K" then
        	card_details[11]=card_details[11]+1
        elseif yourCard[i] == "*" then      --小王
        	card_details[14] = card_details[14]+1
        elseif yourCard[i] == "$" then      --大王
        	card_details[15] =card_details[15]+1
        elseif yourCard[i] == 1 then
        	card_details[12]=card_details[12]+1
        elseif yourCard[i] == 2 then
        	card_details[13]=card_details[13]+1
        else
        	card_details[yourCard[i]-2]=card_details[yourCard[i]-2]+1
        end
    end
end

--[[
函数：King
参数：无
意义：是否有王炸可以出
--]]
function King()
	if(card_details[14] == 1 and card_details[15] == 1) then
		print("*$")
	end
end

--[[
函数：Single
参数：对方出的牌
意义：对方出单牌的解决方法
--]]
function Single(number)
	if number == 0 then  ----当为0时，按序输出不做比较
		for i in ipairs(card_details) do
		    if card_details[i] ~= 0 then
			    print(card_show[i] .. ",")
		    end	
		end
		return
	end

	local number_index = card_show_index[number]
	for i in ipairs(card_details) do
		if card_details[i] ~= 0 and i>number_index then
			print(card_show[i] .. ",")
		end
	end
	Quaderaple(0)
	King()
end

--[[
函数：Double
参数：对方出的牌
意义：对方出一对牌的解决方法
--]]
function Double(number)
	if number == 0 then   ----当为0时，按序输出不做比较
		for i in ipairs(card_details) do
		    if card_details[i] >2 then
			    print(card_show[i] .. card_show[i] .. ",")
		    end	
		end
		return
	end

	local number_index = card_show_index[number]
	for i in ipairs(card_details) do
		if card_details[i] >1 and i>number_index then
			print(card_show[i] .. card_show[i] .. ",")
		end
	end
	Quaderaple(0)
	King()
end

--[[
函数：Triple
参数：对方出的牌
意义：对方出三张一样的牌的解决方法
--]]
function Triple(number)
	if number == 0 then     ----当为0时，按序输出不做比较
		for i in ipairs(card_details) do
		    if card_details[i] >2 then
			    print(card_show[i] .. card_show[i] .. card_show[i] .. ",")
		    end	
		end
		return
	end
	local number_index = card_show_index[number]
	for i in ipairs(card_details) do
		if card_details[i] >2 and i>number_index then
			print(card_show[i] .. card_show[i] .. card_show[i] .. ",")
		end
	end
	Quaderaple(0)
	King()
end

--[[
函数：Quaderaple
参数：对方出的牌
意义：对方出炸弹的解决方法
--]]
function Quaderaple(number)
	if number == 0 then    --当为0时，按序输出不做比较
		for i in ipairs(card_details) do
		    if card_details[i] >3 then
			    print(card_show[i] .. card_show[i] .. card_show[i] .. card_show[i] .. ",")
		    end	
		end
		return
	end

		local number_index = card_show_index[number]
	for i in ipairs(card_details) do
		if card_details[i] >3 and i>number_index then
			print(card_show[i] .. card_show[i] .. card_show[i] .. card_show[i] .. ",")
		end
	end
	King()
end


--[[
函数：TriToOne
参数：对方出的牌
意义：对方出三带一的解决方法
--]]
function TriToOne(number)
	local number_index = card_show_index[number]
	for i in ipairs(card_details) do
		if card_details[i] > 2 and i>number_index  then
			local temp=card_details[i]
			card_details[i]=0
			print(card_show[i] .. card_show[i] .. card_show[i] .. ",")
			print("------------------------------")
            Single(0)
            print("------------------------------")
            card_details[i]=temp
        end
    end
	Quaderaple(0)
	King()
end

--[[
函数：TriToOne2
参数：对方出的牌
意义：对方出三带一对的解决方法
--]]
function TriToOne2(number)
	local number_index = card_show_index[number]
	for i in ipairs(card_details) do
		if card_details[i] > 2 and i>number_index  then
			local temp=card_details[i]
			card_details[i]=0
			print(card_show[i] .. card_show[i] .. card_show[i] ..",")
			print("------------------------------")
            Double(0)
            print("------------------------------")
            card_details[i]=temp
        end
    end
	Quaderaple(0)
	King()
end

--[[
函数：QuadToTwo
参数：对方出的牌
意义：对方出四带二的解决方法
--]]
function QuadToTwo(number)
	local number_index = card_show_index[number]
	for i in ipairs(card_details) do
		if card_details[i] > 3 and i>number_index  then
			local temp=card_details[i]
			card_details[i]=0
			print(card_show[i] .. card_show[i] .. card_show[i] .. card_show[i] ..",")
			print("------------------------------")
			    for j in ipairs(card_details) do
					if card_details[j] ~= 0 then
						local temp1=card_details[j]
			            card_details[j]=0
			            for k in ipairs(card_details) do
			            	if card_details[k] ~= 0 then
			            		print(card_show[j] .. "," .. card_show[k])
			            	end
			            end
			            card_details[j]=temp1
					end
				end
            print("------------------------------")
            card_details[i]=temp
        end
    end
	King()
end

--[[
函数：QuadToTwo2
参数：对方出的牌
意义：对方出四带二对的解决方法
--]]
function QuadToTwo2(number)
    local number_index = card_show_index[number]
	for i in ipairs(card_details) do
		if card_details[i] > 3 and i>number_index  then
			local temp=card_details[i]
			card_details[i]=0
			print(card_show[i] .. card_show[i] .. card_show[i] .. card_show[i] ..",")
			print("------------------------------")
			    for j in ipairs(card_details) do
					if card_details[j] > 1 then
						local temp1=card_details[j]
			            card_details[j]=0
			            for k in ipairs(card_details) do
			            	if card_details[k] >1  then
			            		print(card_show[j] .. card_show[j].."," .. card_show[k]..card_show[k])
			            	end
			            end
			            card_details[j]=temp1
					end
				end
            print("------------------------------")
            card_details[i]=temp
        end
    end
	King()
end

--[[
函数：SeriseSingle
参数：number_head:链子的头 number_head:链子的尾
意义：对方出单链子的解决方法
--]]
function SeriseSingle(number_head,number_tail)
	local now_string="" --现在牌面
	local OP_len = card_show_index[number_tail] - card_show_index[number_head] + 1 --对手牌长
    local now_pos = 1 --现在收集到的位置
    local now_head= 0 --现在牌的第一个牌
    local now_len = 0 --现在已经收集牌的长度
    while now_len+ 13 - now_pos > OP_len do --自己现在剩余牌可以利用牌和对手牌长对比
        if card_details[now_pos] == 0 then
            now_head=now_pos+1
            now_len=0
        else
        	now_len=now_len+1
        	if now_len == OP_len then
        		--print(now_len,OP_len,now_head,now_pos)
        	    for i=now_head,now_pos do
        	        now_string=now_string .. card_show[i] .. ","
        	    end
        	    if now_head>card_show_index[number_head] then
        	        print(now_string)
        	    end
        	    now_string=""
        	    now_head=now_head+1
        	    now_len=now_len-1
            end
        end
        now_pos=now_pos + 1
    end 
    King()
    Quaderaple(0)
end

--[[
函数：SeriseDouble
参数：number_head:连对的头 number_head:连对的尾
意义：对方出连对的解决方法
--]]
function SeriseDouble(number_head,number_tail)
	local now_string="" --现在牌面
	local OP_len = card_show_index[number_tail] - card_show_index[number_head] + 1 --对手牌长
    local now_pos = 1 --现在收集到的位置
    local now_head= 0 --现在牌的第一个牌
    local now_len = 0 --现在已经收集牌的长度
    while now_len+ 13 - now_pos > OP_len do --自己现在剩余牌可以利用牌和对手牌长对比
        if card_details[now_pos] < 2 then
            now_head=now_pos+1
            now_len=0
        else
        	now_len=now_len+1
        	if now_len == OP_len then
        	    for i=now_head,now_pos do
        	        now_string=now_string .. card_show[i] .. card_show[i] .. ","
        	    end
        	    if now_head>card_show_index[number_head] then
        	        print(now_string)
        	    end
        	    now_string=""
        	    now_head=now_head+1
        	    now_len=now_len-1
            end
        end
        now_pos=now_pos + 1
    end 
    King()
    Quaderaple(0)
end

--[[
函数：SeriseTriple
参数：number_head:三连对的头 number_head:三连对的尾
意义：对方出三连对的解决方法
--]]
function SeriseTriple(number_head,number_tail)
	local now_string="" --现在牌面
	local OP_len = card_show_index[number_tail] - card_show_index[number_head] + 1 --对手牌长
    local now_pos = 1 --现在收集到的位置
    local now_head= 0 --现在牌的第一个牌
    local now_len = 0 --现在已经收集牌的长度
    while now_len+ 13 - now_pos > OP_len do --自己现在剩余牌可以利用牌和对手牌长对比
        if card_details[now_pos] < 3 then
            now_head=now_pos+1
            now_len=0
        else
        	now_len=now_len+1
        	if now_len == OP_len then
        		--print(now_len,OP_len,now_head,now_pos)
        	    for i=now_head,now_pos do
        	        now_string=now_string .. card_show[i].. card_show[i].. card_show[i] .. ","
        	    end
        	    if now_head>card_show_index[number_head] then
        	        print(now_string)
        	    end
        	    now_string=""
        	    now_head=now_head+1
        	    now_len=now_len-1
            end
        end
        now_pos=now_pos + 1
    end 
    King()
    Quaderaple(0)
end

AddDetails()
--Single("J")
--Double("J")
--Triple("J")
--Quaderaple("J")
--TriToOne(3)
--TriToOne2(3)
--QuadToTwo(3)
--QuadToTwo2(3)
--SeriseSingle(7,"Q")
--SeriseDouble(3,8)
SeriseTriple(3,4)