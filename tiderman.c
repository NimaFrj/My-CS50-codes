#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
bool check(int m, int n);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int k = 0; k < candidate_count; k++)
    {
        if (strcmp(name, candidates[k]) == 0)
        {
            ranks[rank] = k;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int k = 0; k < candidate_count; k++)
    {
        for (int h = k + 1; h < candidate_count; h++)
            preferences[ranks[k]][ranks[h]] += 1;
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[i].winner = i;
                pairs[i].loser = j;
                pair_count += 1;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[i].winner = j;
                pairs[i].loser = i;
                pair_count += 1;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    int j;
    int k;
    int strength[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        j = pairs[i].winner;
        k = pairs[i].loser;
        strength[i] = preferences[j][k];
    }
    // selection sorting
    int max = strength[0];
    int index = 0;
    pair a;
    pair b;
    for (int m = 0; m < candidate_count; m++)
    {
        for (int n = m; n < candidate_count; n++)
        {
            if (max < strength[n])
            {
                max = strength[n];
                index = n;
            }
        }
        a = pairs[m];
        b = pairs[index];
        pairs[m] = b;
        pairs[index] = a;
        max = 0;
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    int m;
    int n;
    for (int i = 0; i < pair_count - 1; i++)
    {
        m = pairs[i].winner;
        n = pairs[i].loser;
        if (check(m, n) == 0)
        {
            locked[m][n] = 1;
        }
    }
    return;
}

bool check(int m, int n)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[n][i] == 1)
        {
            if (i == m)
            {
                return 1;
            }
            if (check(m, i) == 0)
            {
                continue;
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (!locked[j][i] == 0)
            {
                break;
            }
        }
        printf("%s\n", candidates[i]);
        return;
    }
    return;
}
