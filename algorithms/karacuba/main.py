#множення чисел методом Карацуби (довга арифметика)

def norm(a, b): #преведення двох чисел до однакової довжини й парного вигляду
    len_a = len(a)
    len_b = len(b)
    if len_a > len_b:
        if (len_a % 2) != 0:
            a = "0" + a
            len_a += 1
            b = "0"*(len_a-len_b) + b
        else:
            b = "0"*(len_a-len_b) + b
    elif len_a < len_b:
        if (len_b % 2) != 0:
            b = "0" + b
            len_b += 1
            a = "0"*(len_b-len_a) + a
        else:
            a = "0"*(len_b-len_a) + a
    elif len_a == len_b:
        if (len_a % 2) != 0:
            a = "0" + a
            b = "0" + b
    return(a, b)

def karacuba(x, y):
    global i  #лічільник суми ad+bc з певним значенням (для завдання)
    if len(x) == 1:  #якщо на вході лишилися одинарні чила, до повертаємо їх добуток
        return(int(x) * int(y))
    x, y = norm(x, y)  #вирівнюємо числа
    len_x2 = len(x)//2
    len_y2 = len(y)//2
    a = x[:len_x2]    #розділяємо кожне число на дві частини
    b = x[len_x2:]
    c = y[:len_y2]
    d = y[len_y2:]
    print("a=" + a + " b=" + b + " c=" + c + " d=" + d)
    ab = str(int(a) + int(b))  #сума a + b
    cd = str(int(c) + int(d))  #сума c + d
    ac = (karacuba(a, c))  #рекурсивно викликаємо функцію для обрахунку добутків менших чисел (a * c) та (b * d)
    bd = (karacuba(b, d))
    adbc = int(karacuba(ab, cd)) - int(ac) - int(bd)  #знаходимо суму ad+bc
    if adbc == 12:  #лічильник суми ad+bc з певним значенням
        i += 1
    print("ab=" + ab + " cd=" + cd + " adbc=" + str(adbc))
    return(10 ** (len_x2*2)*ac + 10 ** (len_x2)*adbc + bd)  #повертаємо значення

i = 0
x = '1685287499328328297814655639278583667919355849391453456921116729'
y = '7114192848577754587969744626558571536728983167954552999895348492'

x, y = norm(x, y)
print(x, y)
m = karacuba(x, y)
print("Добуток = " + str(m))
n = int(x) * int(y)
print("Перевірка=" + str(n))
print(i)
