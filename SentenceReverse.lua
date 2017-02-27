--i am a student 变成student a am i
function SentenceReverse(inputString)
	outputString=""
	tempString=""
	count = string.len(inputString)
	for i=count,1,-1 do
		nowChar = string.sub(inputString,i,i)
	    if nowChar ~= " " then
	    	tempString = nowChar .. tempString
        else
        	outputString = outputString .. tempString .. " "
        	tempString = ""
        end
	end
	outputString = outputString .. tempString
	print(outputString)
end


SentenceReverse("i am a student")
