import calendar
y=int(input("enter the year"))
m=1
print("\n******CALENDAR******")
Cal = calendar.TextCalendar(calendar.SUNDAY)
i=1
while i<=12:
    Cal.prmonth(y,i)
    i+=1
    
