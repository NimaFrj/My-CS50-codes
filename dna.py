import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python tournament.py FILENAME")

    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1]) as file:
        dictrow = csv.DictReader(file)
        for row in dictrow:
            database.append(row)
    # print(database)

    # TODO: Read DNA sequence file into a variable
    f = open(sys.argv[2], "r")
    seq = f.read()

    # TODO: Find longest match of each STR in DNA sequence
    strs = [x for x in database[0]]
    strs.remove("name")
    output = {}
    for i in strs:
        output[i] = longest_match(seq, i)
    # print(output)

    # TODO: Check database for matching profiles
    for j in range(len(database)):
        k = 0
        for dna in output:
            if output[dna] != int(database[j][dna]):
                break
            k += 1
            if k == len(output):
                print(database[j]['name'])
                return
    print("No match")
    return

    for i, dna in enumerate(output):
        for j in range(len(database)):
            if output[dna] != int(database[i][dna]):
                break


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
