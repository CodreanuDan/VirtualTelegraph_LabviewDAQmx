import matplotlib.pyplot as plt
import numpy as np

morse_code = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..',
    'E': '.',  'F': '..-.', 'G': '--.',  'H': '....',
    'I': '..', 'J': '.---', 'K': '-.-',  'L': '.-..',
    'M': '--', 'N': '-.',   'O': '---',  'P': '.--.',
    'Q': '--.-','R': '.-.', 'S': '...',  'T': '-',
    'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-',
    'Y': '-.--','Z': '--..', ' ': ' '
}

dot_duration = 1
dash_duration = 3
intra_char_space = 1
inter_char_space = 3
inter_word_space = 7

def text_to_morse_signal(text):
    signal = []
    delimitari = []
    simboluri = []  
    pozitie_curenta = 0

    text = text.upper()
    for i, char in enumerate(text):
        if char == ' ':
            signal += [0] * inter_word_space
            pozitie_curenta += inter_word_space
            delimitari.append((pozitie_curenta, 'cuvant'))
            continue

        morse = morse_code.get(char, '')
        for j, symbol in enumerate(morse):
            durata = dot_duration if symbol == '.' else dash_duration
            signal += [1] * durata
            simboluri.append((pozitie_curenta, durata, symbol))  
            pozitie_curenta += durata

            if j < len(morse) - 1:
                signal += [0] * intra_char_space
                pozitie_curenta += intra_char_space

        if i < len(text) - 1 and text[i+1] != ' ':
            signal += [0] * inter_char_space
            pozitie_curenta += inter_char_space
            delimitari.append((pozitie_curenta, 'litera'))

    return signal, delimitari, simboluri

def plot_morse_signal(text):
    signal, delimitari, simboluri = text_to_morse_signal(text)
    time = np.arange(len(signal))
    
    plt.figure(figsize=(16, 4))
    plt.step(time, signal, where='post', linewidth=2)
    plt.ylim(-0.5, 2)
    plt.xlabel('Timp (unități arbitrare)')
    plt.ylabel('Semnal')
    plt.title(f'Semnal Morse pentru: "{text}"')
    plt.grid(True)

    for poz, tip in delimitari:
        color = 'orange' if tip == 'litera' else 'red'
        label = f'Delimitare {tip}'
        if label not in plt.gca().get_legend_handles_labels()[1]:
            plt.axvline(poz, color=color, linestyle='--', label=label)
        else:
            plt.axvline(poz, color=color, linestyle='--')

    for start, durata, simbol in simboluri:
        plt.axvline(start, color='green', linestyle=':', alpha=0.6)
        plt.text(start + durata / 2, 1.1, simbol, ha='center', va='bottom', fontsize=12, fontweight='bold')

    plt.legend()
    plt.tight_layout()
    plt.show()

plot_morse_signal("SOS")
