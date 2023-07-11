def get_max_len(words):
    max_len = 0
    for word in words:
        if len(word) > max_len:
            max_len = len(word)
    return max_len

def get_permutations(words: list) -> str:
    """
    WORDS is a list of words that are anagrams of each other.
    returns a list of str representing the how the letters are permuted.
    """

    permutations = []
    for word1 in words:
        for word2 in words:
            if word1 == word2:
                continue
            permutation = ""
            for c in word1:
                permutation += str(word2.find(c))

            if permutation not in permutations:
                permutations.append(permutation)

    return permutations

    

def main():
    # read file
    with open("input_files/098peuler.txt", "r") as f:
        words = f.read().split(",")

    # sort words by length
    words.sort(key=len, reverse=True)

    # remove quotes from words
    words = [word[1:-1] for word in words]

    # find anagrams of each word
    anagrams = {}
    for word in words:
        key = "".join(sorted(word))
        if key in anagrams:
            anagrams[key].append(word)
        else:
            anagrams[key] = [word]

    for key in list(anagrams.keys()):
        if len(anagrams[key]) < 2:
            del anagrams[key]


    # change the dict to be a tuple of anagrams and their permutations
    for key in anagrams:
        anagrams[key] = tuple((anagrams[key], get_permutations(anagrams[key])))
    
    # get max length of key
    max_len = get_max_len(anagrams.keys())

    # get max square
    max_square = 10**(max_len)

    # generate all squares up to max_square
    squares = [n**2 for n in range(1, int(max_square**0.5)+1)]

    # find squares that are anagrams of each other
    sq_anagrams = {}
    for square in squares:
        square = str(square)
        key = "".join(sorted(square))
        if key in sq_anagrams:
            sq_anagrams[key].append(square)
        else:
            sq_anagrams[key] = [square]

    for key in list(sq_anagrams.keys()):
        if len(sq_anagrams[key]) < 2:
            del sq_anagrams[key]

    # change the dict to be a tuple of anagrams and their permutations
    for key in sq_anagrams:
        sq_anagrams[key] = tuple((sq_anagrams[key], get_permutations(sq_anagrams[key])))

    # find permutations in anagrams that are also in sq_anagrams
    for key in anagrams:
        perms = anagrams[key][1]
        for key_sq in sq_anagrams:
            perms_sq = sq_anagrams[key_sq][1]
            for perm in perms:
                if perm in perms_sq:
                    print(anagrams[key], sq_anagrams[key_sq])
                    return


if __name__ == "__main__":
    main()