from pprint import pprint


def main():
    text = input('text: ')
    letters_count = {letter: text.count(letter) for letter in set(text)}
    pprint(letters_count)


if __name__ == '__main__':
    main()
