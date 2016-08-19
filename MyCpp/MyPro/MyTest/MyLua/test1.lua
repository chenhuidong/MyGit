function sum(a,b)
	return a+b
end

function minus(a,b)
	return a-b
end

function testclass(a,b)
	mytest = CTest:new()
	mytest:SetA(a)
	mytest:SetB(b)
	print(mytest:GetA())
	print(mytest:GetB())
	return mytest
end