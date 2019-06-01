#coding:utf-8
groupmates = [
    {
        "name": u"Василий",
        "group": "1701",
        "age": 19,
        "marks": [3, 4, 3, 2, 2]
    },
    {
        "name": u"Никита",
        "group": "1703",
        "age": 19,
        "marks": [4, 3, 5, 2, 5]
    },
    {
        "name": u"Екатерина",
        "group": "1708",
        "age": 23,
        "marks": [5, 5, 5, 5, 4]
    },
    {
        "name": u"Георгий",
        "group": "1704",
        "age": 20,
        "marks": [2, 2, 2, 2, 2]
    },
    {
        "name": u"Павел",
        "group": "1701",
        "age": 18,
        "marks": [5, 4, 5, 5, 4]
    }
]

def print_students(students):
    print u"Имя студента".ljust(15), \
          u"Группа".ljust(8), \
          u"Возраст".ljust(8), \
          u"Оценки".ljust(20)
    for student in students:
        print \
              student["name"].ljust(15), \
              student["group"].ljust(8), \
              str(student["age"]).ljust(8), \
              str(student["marks"]).ljust(20)
    print "\n"
print_students(groupmates)

def fun(students, av):
    print u"Сортировка по средней оценке."
    print u"Имя студента".ljust(15), \
          u"Группа".ljust(8), \
          u"Возраст".ljust(8), \
          u"Оценки".ljust(20)
    for student in students:
        if sum(student["marks"]) / len(student["marks"]) >= av:
            print \
              student["name"].ljust(15), \
              student["group"].ljust(8), \
              str(student["age"]).ljust(8), \
              str(student["marks"]).ljust(20)
fun(groupmates, 3)
