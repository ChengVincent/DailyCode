--[[采用面向对象的思想，试设计一个图书管理系统。（写出关键结构和对象方法就好）
图书管理基本业务活动包括：对一本书的采编入库、清除库存、借阅和归还等等。
每种书的登记内容至少包括书号、书名、著者、现存量和总库量等五项。
作为演示系统，不必使用文件.
功能概述：
入库:   每购入一种书，经分类和确定书号之后登记到图书账目中,如果账目已有就添加.
清除库存: 某种书已没有价值，将它从库中注销.
借阅： 如果一种书的显存大于0，则可以借出, 登记借阅者的图书证号和归还期限.
归还： 注销对借阅者的登记，改变库存量.
显示： 列出库存中的所有书籍.
--]]
 
book = {
    book_number = "000",
	book_name = "NoName",
    book_auther = "NoAuthor",
    book_now_stock = 0,
    book_all_stock = 0,
    borrow_details = {}
}--书的信息

--添加书的信息
function book:add(number,name,author,stock)
	self.book_number=number
	self.book_name=name
	self.book_auther=author
	self.book_now_stock=stock
	self.book_all_stock=stock
end

--删除书的信息
function book:Delete()
	self=nil
end

--新建一本书
function book:new(o)
	o = o or {}
	setmetatable(o,self)
	self.__index=self
	return o
end

--借书
function book:borrow(name,number)
	if self.book_now_stock == 0 then
		do return end
	end
    self.book_now_stock=self.book_now_stock - 1
    self.borrow_details[self.book_all_stock - self.book_now_stock] ={[1]=name,[2]=number}
end

--输出书信息
function book:outputDetails()
	print("book_number:" .. self.book_number)
	print("book_name:" .. self.book_name)
	print("book_auther:" .. self.book_auther)
	print("book_now_stock:" .. self.book_now_stock)
	print("book_all_stock:" .. self.book_all_stock)
	if self.borrow_details == {} then
		do return end
	else
		print("borrow_details:")
		for i in ipairs(self.borrow_details) do
			print("name:" .. self.borrow_details[i][1] ..",number:" .. self.borrow_details[i][2])
        end
    end
end

--测试
book1=book:new()
book1:add("001","lua","luaMaster",7)
book1:borrow("chaozhou","20170201")
book1:outputDetails()
