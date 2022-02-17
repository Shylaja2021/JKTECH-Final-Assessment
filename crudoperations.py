import sqlite3

def connection():
    con=sqlite3.connect("student.db")
    return con

def create(con):
    cur=con.cursor()
    cur.execute("create table Students(id integer,name text,age integer,course text);")
    con.close()


def insert(con):
    cur=con.cursor()
    cur.executescript("""
    insert into Students values(1001,"john",21,"MCA");
    insert into Students values(1002,"peter",22,"MSC");
    insert into Students values(1003,"shylaja",20,"MCA");
    """)
    con.commit()
    con.close()

def read(con):
    cur=con.cursor()
    cur.execute("select * from Students")
    data=cur.fetchall()
    for d in data:
        print(d)
    con.close()

def delete(con):
    cur=con.cursor()
    cur.execute("select * from Students")
    print("details before delete")
    data=cur.fetchall()
    for i in data:
        print(i)
    id=int(input("enter id to delete :"))
    cur.execute('delete from Students where id = ?',(id,))
    con.commit()
    cur.execute("select * from Students")
    print("details after delete")
    data=cur.fetchall()
    for d in data:
        print(d)
    con.close()

def update(con):
    cur = con.cursor()
    cur.execute("select * from Students")
    print("details before update")
    data = cur.fetchall()
    for i in data:
        print(i)
    id = int(input("enter id  :"))
    name=input("enter changed name to update : ")
    cur.execute('update Students set name=? where id = ?', (name,id))
    con.commit()
    cur.execute("select * from Students")
    print("details after update")
    data = cur.fetchall()
    for d in data:
        print(d)
    con.close()


con=connection()
create(con)

con=connection()
insert(con)
print("**********************display**********************")
con=connection()
read(con)
print("**********************delete**********************")
con=connection()
delete(con)
print("**********************update**********************")
con=connection()
update(con)
