# Filename: reconstructSentence.py
# Takes two input files, reverses their text and combines each line of text
# Reverse function is NOT used

def reconstruct_sentence(file1, file2, output_file):
  with open(file1, 'r') as f1, open(file2, 'r') as f2:
    words1 = f1.read().split()
    words2 = f2.read().split()

  combined_words = []
  while words1 or words2:
    if words1:
      combined_words.append(words1[-1])
      words1 = words1[:-1]
    if words2:
      combined_words.append(words2[-1])
      words2 = words2[:-1]
  
  reconstructed_text = ' '.join(combined_words)

  with open(output_file, 'w') as out:
    out.write(reconstructed_text)

  print(f"Reconstructed sentence written to {output_file}.")

if __name__ == "__main__":
  reconstruct_sentence("input1.txt", "input2.txt", "output.txt")
