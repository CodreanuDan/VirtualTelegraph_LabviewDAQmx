int i, j;
int morse_index = 0;
int morse_buffer[100]; // buffer pentru iesire
int letter_buffer[20]; // buffer temporar pentru o litera
int letter_len = 0;
int morse_out[100];

for (i = 0; i < input_len; i++)
{
    int code = input[i];

    if (code == 1)
    {
        letter_buffer[letter_len++] = 46; // '.' = ASCII 46
    }
    else if (code == 2)
    {
        letter_buffer[letter_len++] = 45; // '-' = ASCII 45
    }
    else if (code == 3)
    {
        for (j = 0; j < letter_len; j++)
        {
            morse_buffer[morse_index++] = letter_buffer[j];
        }
        letter_len = 0;
        morse_buffer[morse_index++] = 32; // space = ASCII 32
    }
    else if (code == 4)
    {
        for (j = 0; j < letter_len; j++)
        {
            morse_buffer[morse_index++] = letter_buffer[j];
        }
        letter_len = 0;
        morse_buffer[morse_index++] = 32;
        morse_buffer[morse_index++] = 32;
        morse_buffer[morse_index++] = 32;
    } // codul 0 (pauza scurta) se ignora
}

// Daca mai exista ceva în letter_buffer, il copiem la final
for (j = 0; j < letter_len; j++)
{
    morse_buffer[morse_index++] = letter_buffer[j];
}

// Copiem rezultatul în morse_out[]
for (i = 0; i < morse_index; i++)
{
    morse_out[i] = morse_buffer[i];
}

// Setam lungimea efectiva
morse_len = morse_index;
