# TODO
import cs50
card = cs50.get_string("enter: ")


def validation(number):
    sum_1 = 0
    sum_2 = 0
    for i in range(0, len(number), 2):
        if (int(number[i]) * 2) > 9:
            sum_1 = sum_1 + 1 + (int(number[i]) * 2) % 10
        else:
            sum_1 += int(number[i]) * 2
    for i in range(1, len(number), 2):
        sum_2 += int(number[i])
    if (sum_1 + sum_2) % 10 == 0:
        return True
    else:
        return False


if len(card) == 15 and (card[0:2] == '34' or card[0:2] == '37') and validation(card):
    print("AMEX")

elif len(card) == 16 and (int(card[0:2]) > 50 and int(card[0:2]) < 56) and validation(card):
    print("MASTERCARD")

elif (len(card) == 16 or len(card) == 13) and card[0] == '4' and validation(card):
    print("VISA")

else:
    print("INVALID")
