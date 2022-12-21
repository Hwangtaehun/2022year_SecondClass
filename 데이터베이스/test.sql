use madang;
-- select * from Book;

-- select '-- ordering';

-- /*select * from Book order by publisher asc;*/
-- select * from Book order by publisher desc;

-- select '-- grouping';
-- select * from book group by publisher;
-- select publisher, count(*) from Book group by publisher;
-- select publisher, count(bookname) from Book group by publisher having count(bookname) >= 2;

-- select count(distinct publisher) from book; 출판사 종류의 개수
-- select distinct count(publisher) from book; 테이블의 정보개수

-- select * from book where price < 20000;

-- select * from book where price between 10000 and 20000;

-- select * from book where price = 7000 or price = 8000; == select * from book where price in(7000, 8000);

-- select distinct publisher from book where price < 10000;

-- select publisher, bookname, price from book where publisher = '굿스포츠' or publisher = '삼성당';
-- select publisher, bookname, price from book where publisher in ( select distinct publisher from book where price < 10000 );

-- select publisher, bookname, price from book where publisher not in ( select distinct publisher from book where price < 10000 );

-- select publisher, bookname, price from book where bookname like '%축구%' -- '축구'가 들어 있는것을 검색

-- select publisher, bookname, price from book where bookname like '%구%' -- '구'가 들어 있는것을 검색

-- select publisher, bookname, price from book where bookname like '구%' -- '구'라고 시작하는 것을 검색

-- select publisher, bookname, price from book where bookname like '%해' -- '해'라고 끝나는 것을 검색

-- select publisher, bookname, price from book where bookname like '%구%해' -- '~구~해'라고 끝나는 것을 검색

-- select publisher, bookname, price from book where bookname like '축%해' -- '축~해'라고 끝나는 것을 검색

-- select publisher, bookname, price from book where bookname like '[0-9]%' -- '0-9'까지 일치하는 문자 검색

-- select * from Customer; -- Customer 다 찾아보기
-- select * from Customer where phone IS NULL;

-- select * from book where publisher '굿스포츠' or '대한미디어'; --== select * from book where publisher in ('굿스포츠', '대한미디어');

-- select * from book where bookname like '%축구%' and price >= 2000;

-- select * from book order by order price desc, bookname asc;

-- select sum(saleprice) from orders;

-- select sum(saleprice) as '총매출액' from orders;

-- select sum(saleprice) as '총구매액' from orders where custid = 2;
-- select sum(saleprice) as '총구매액' from orders where custid in (select custid from Customer where name = '김연아');
-- select sum(saleprice) as '총구매액' from orders, customer where orders.custid = customer.custid and customer.name = '김연아'; --조인 사용

-- select * from order, customer -- 카티션프로덕트됨 where customer.name = '김연아' -->김연아 추출;

-- select sum(saleprice) as '총구매액' avg(saleprice) as "평균판매액", min(saleprice) as '최소구매액', max(saleprice) as '최고구매액' from orders;

--10월 28일
-- select * from book;

--select count(distinct custid) AS '중복 없이 출력' from orders;

-- select * from orders order by custid;

--select custid, count(bookid) as '도서수량', sum(saleprice) as '총판매액' from orders group by custid;

--select custid, count(bookid) as '주문도서 총수량' from orders where saleprice >= 8000 group by custid having count(bookid) > 1;

--select bookname from book where bookid like 1;

-- select bookname from book where price >= 20000;

-- select * from orders where custid =1;
-- select sum(saleprice) as '총구매액' from orders where custid = 1; 

--select count(bookid) as ' 도서의 수' from orders where custid = 1;
--select customer.name, count(orders.bookid) as ' 도서의 수' from orders, customer where orders.custid = customer.custid and customer.name = '박지성';

--select count(bookid) from book;
--select count(distinct publisher) from book;
--select name, address from customer;
--select orderid from orders where orderdate between '2014-07-04' and '2014-07-07';
--select orderid from orders where orderdate not between '2014-07-04' and '2014-07-07'; --이거 실행가능
-- select name, address from customer where name like '김%';
-- select name, address from customer where name like '김%아';

-- select customer.name, book.bookname from customer, orders, book where customer.custid = orders.custid and orders.bookid = book.bookid;

-- select * from customer, orders where customer.custid = orders.custid order by customer.custid -- order by 정렬;

-- select customer.name, book.price - orders.saleprice as '할인액' from customer, orders, book where customer.custid = orders.custid and orders.bookid = book.bookid;
-- select customer.name, sum(book.price - orders.saleprice) as '총할인액' from customer, orders, book where customer.custid = orders.custid and orders.bookid = book.bookid group by customer.custid; 

-- select customer.name, sum(orders.saleprice) as '총판매액' from customer, orders where customer.custid = orders.custid group by customer.name order by customer.name;

-- select name, bookname from customer, orders, book where customer.custid = orders.custid and book.bookid = orders.bookid and book.price = 20000;
-- select * from book where bookname = '야구의 추억';

-- select customer.name, orders.saleprice from customer inner join orders on customer.custid = orders.custid where customer.name = '김연아'; -- == select customer.name, orders.saleprice from customer, orders where customer.name = '김연아' and customer.custid = orders.custid;

-- select customer.name, orders.saleprice from customer left outer join orders on customer.custid = orders.custid;

-- select bookid, bookname from book where price = (select max(price) from book) -- select max(price) from book; + select bookid, bookname from book where price = 35000; 

-- select distinct customer.name from customer, orders where customer.custid in(select orders.custid from orders); -- == select distinct customer.name from customer, orders where customer.custid = orders.custid;

-- select distinct customer.name from customer, orders where customer.custid not in(select distinct orders.custid from orders);

-- select customer.name from customer, orders where customer.custid = orders.custid and bookid in(select bookid from book where publisher = '대한미디어');

-- select publisher, bookname, price from book where price > (select avg(price) from book);

-- select publisher, price from book order by publisher;
-- select publisher, avg(price) from book group by publisher;

-- select publisher, price from book where publisher = (Pearson, 굿스포츠) and price > (13000, 7000);

-- select b1.bookname, b1.publisher from book b1 where b1.price > (select avg(b2.price) from book b2 where b2.publisher = b1.publisher) order by publisher;
-- select b1.bookname, b1.publisher from book b1 where b1.publisher = 'Pearson' and b1.price > (select avg(b2.price) from book b2 where b2.publisher = b1.publisher);
-- select b1.bookname, b1.publisher from book b1 where b1.publisher = '굿스포츠' and b1.price > (select avg(b2.price) from book b2 where b2.publisher = b1.publisher);
-- select b1.bookname, b1.publisher from book b1 where b1.publisher = '대한미디어' and b1.price > (select avg(b2.price) from book b2 where b2.publisher = b1.publisher);
-- select b1.bookname, b1.publisher from book b1 where b1.publisher = '삼성당' and b1.price > (select avg(b2.price) from book b2 where b2.publisher = b1.publisher);
-- select b1.bookname, b1.publisher from book b1 where b1.publisher = '이상미디어' and b1.price > (select avg(b2.price) from book b2 where b2.publisher = b1.publisher);