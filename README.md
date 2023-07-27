# FYP

DROP TABLE IF EXISTS SysUser;

CREATE TABLE SysUser
(
   UserId    VARCHAR(10) PRIMARY KEY,
   UserPw    VARBINARY(50) NOT NULL,
   FullName  VARCHAR(50) NOT NULL,
   Email     VARCHAR(50) NOT NULL,
   UserRole  VARCHAR(10) NOT NULL,
   ATT      INT NOT NULL,
   BTT      INT NOT NULL,
   AHT      INT NOT NULL,
   BHT      INT NOT NULL
);

INSERT INTO SysUser(UserId, UserPw, FullName, Email, UserRole, ATT, BTT, AHT, BHT) VALUES
('dan', HASHBYTES('SHA1', '1232'), 'Daniel Chung', 'Dan@FYP.com', 'admin', 40, 20, 70, 30),
('earn', HASHBYTES('SHA1', '123'), 'Earnest Lim', 'Earn@xyc.com', 'farmer', 25, 10, 200, 10);
('eddie', HASHBYTES('SHA1', '123'), 'Eddie Koh', 'Eddie@xyc.com', 'farmer', 40, 30, 200, 10);
