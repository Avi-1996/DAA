class Student:
     def getinfo(self):
          self.name=input("enter the student name =")
          self.number =input("enter the student number")
          try:
               f=open("info.txt","a")
               data =self.name + "&" +self.number + "\n"
               f.write(data)
          except:
               print("Error In File Opening")
     def search(self):
          while(1):
               choice =int(input("Enter 1 for seaching number 2 for seaching name and for Quit enter 3 \t "))
               if choice == 1:
                    flag=0
                    name = input("enter the name of student\t")
                    try:
                         f=open("info.txt","r")
                         lines = f.readlines()
                         for line in lines:
                              nam,number = line.split("&")
                              if nam == name:
                                   print()
                                   print()
                                   print("\t\tname found")
                                   print("\t\tthe number of",nam,"is",number)
                                   flag=1
                                   break;
                         if flag == 0:
                              print("name NOt found")
                         f.close()
                    except:
                         print("Error")
                    break;
               elif choice == 2:
                    flag=0
                    num = input("enter the number of student")
                    try:
                         f=open("info.txt","r")
                         lines = f.readlines()
                         for line in lines:
                              name,number = line.split("&")
                              if number.strip()== str(num):
                                   print()
                                   print()
                                   print("\t\tNUMBER found")
                                   print("\t\ttheName Of Student Is ",name)
                                   flag=1
                                   break;
                         if flag == 0:
                              print("number NOt found")
                         f.close()
                    except:
                         print("Error")
                    break;
               
ob =Student()
while(1):
     ch=input("\tenter 1 for inserting and 2 for searching 3 for Quit")
     if ch=="1":
          n=int(input("enter the no foir students"))
          for i in range(n):
               ob.getinfo()
     elif ch == "2":
          ob.search()
     elif ch == "3":
          print("Thanks For using our Application")
          break;
                         
