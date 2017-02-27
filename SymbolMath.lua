--成对符号匹配

function SymbolMath(inputString)
	local symbolTable = {
	["("]=0,
    ["'"]=0,
    ["["]=0,
    ["{"]=0,
    ['"']=0
    } --if math all symbol,the number is 0;

    count=string.len(inputString)

    for i=1,count do
    	nowChar=string.sub(inputString, i, i)
    	if nowChar == "(" then
    		symbolTable["("] = symbolTable["("]+1
    	elseif nowChar == ")" then
	        symbolTable["("] = symbolTable["("]-1
	        	if symbolTable["("] == -1 then
	        		return false
	        	end
	    elseif nowChar == "[" then
	        symbolTable["["] = symbolTable["["]+1
	    elseif nowChar == "]" then
	        symbolTable["["] = symbolTable["["]-1
	        	if symbolTable["["] == -1 then
	        		return false
	        	end
	    elseif nowChar == "'" then
	        symbolTable["'"] = symbolTable["'"]+1
	    elseif nowChar == '"' then
	        symbolTable['"'] = symbolTable['"']+1
	    else 
            -- there is nothing
	    end	
	end	
    
    for _,j in pairs(symbolTable) do
    	if j%2 ~= 0 then
    		return false
    	end
    end

    return true
end

d="fks;odkgd\"\"kf"
print(SymbolMath(d))