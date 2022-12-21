-- DROP TABLE IF EXISTS Summer;

-- CREATE TABLE Summer(
--     sid INTEGER,
--     class VARCHAR(20),
--     price INTEGER
-- );
-- desc Summer;

-- INSERT INTO Summer VALUES (100, 'FORTRAN', 20000);
-- INSERT INTO Summer VALUES (150, 'PASCAL', 15000);
-- INSERT INTO Summer VALUES (200, 'C', 10000), (250, 'FORTRAN', 20000);

-- select * from Summer;

--select sid, class from Summer;
--select price from Summer where class like 'C';
--select max(price) from Summer;
--select class from Summer where price = (select max(price) from Summer);
--select count(sid), sum(price) from Summer;
-- select sid from Summer where sid like 200;
-- delete from Summer where sid like 200;
-- select price from Summer where class like 'C';