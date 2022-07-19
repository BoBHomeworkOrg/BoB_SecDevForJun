output = ""
i = 0;

with open("context.enc","rb+") as f:
    str1 = f.read(292)
    output += str1.decode('utf-32') + '\n'

    # 개행 문자 및 쓰래기 문자 제거
    f.read(4)

    str2 = f.read(71)
    output += str2.decode('cp949') + '\n'

    # 개행 문자 및 쓰래기 문자 제거
    f.read(1)

    str3 = f.read(200)
    output += str3.decode('utf-8') + '\n'

    # 개행 문자 및 쓰래기 문자 제거
    f.read(1)

    str4 = f.read(130)
    output += str4.decode('euckr') + '\n'

    # 개행 문자 및 쓰래기 문자 제거
    f.read(1)

    while(i < 69):
        str5 = f.read(1)
        output += str5.decode('cp949')
        output += ' '
        f.read(3)
        i+=1
    output += '\n'

    # 개행 문자 및 쓰래기 문자 제거
    f.read(4)

    str6 = f.read(16)
    output += str6.decode('utf-8') + '\n'

    # 개행 문자 및 쓰래기 문자 제거
    f.read(1)

    str7 = f.read(52)
    output += str7.decode('utf-32') + '\n'

    # 개행 문자 및 쓰래기 문자 제거
    f.read(4)

    str8 = f.read(11)
    output += str8.decode('cp949') + '\n'

    # 개행 문자 및 쓰래기 문자 제거
    f.read(1)

    str9 = f.read(36)
    output += str9.decode('utf-16') + '\n'

    # 개행 문자 및 쓰래기 문자 제거
    f.read(2)

    str10 = f.read(16)
    output += str10.decode('utf-16')

    str11 = f.read(42)
    output += str11.decode('utf-16') + '\n'

    # 개행 문자 및 쓰래기 문자 제거
    f.read(2)

    str12 = f.read(38)
    print(str12)
    output += str12.decode('cp949') + '\n'

    # 개행 문자 및 쓰래기 문자 제거
    f.read(1)

    str13 = f.read(32)
    output += str13.decode('utf-8') + '\n'

    # 개행 문자 및 쓰래기 문자 제거
    f.read(1)

    str14 = f.read(13)
    output += str14.decode('euckr') + '\n'

    # 개행 문자 및 쓰래기 문자 제거
    f.read(1)

    str15 = f.read(39)
    output+= str15.decode('utf-8') + '\n'

    # 개행 문자 및 쓰래기 문자 제거
    f.read(1)

    str16 = f.read(54)
    output += str16.decode('utf-16') + '\n'

    print(output)


fw = open("result.txt",'w+')
fw.write(output)
