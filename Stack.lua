--栈
stackSize = 3
stackNum = 0
newStack = {}

function PushStack(x)
	if stackNum == stackSize then
		print("this stack is full!!!!")
	else
		stackNum = stackNum + 1
		newStack[stackNum] = x
	end
end

function PopStack()
	if stackNum == 0 then
		print("this stack is empty!!!")
	else
		stackNum = stackNum -1
	end
end

function IsEmpty()
	if stackNum == 0 then
		return true
	end
end

function IsFull()
	if stackNum == stackSize then
		return true
	end
end

PushStack(1)
PushStack(2)
PushStack(3)
PushStack(3) --full test

for i in pairs(newStack) do  --insert order test
    print(newStack[i])
end

PopStack()  --empty test
PopStack()
PopStack()
PopStack()
