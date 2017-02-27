--参数转字符串
function ArgToString(...)
	local result
	for i in ipairs(arg) do
        if result then
        	result = result .. arg[i]
        else
        	result = arg[i]
        end
    end
    return result
end

print(ArgToString(23,"dhasu",1,3))