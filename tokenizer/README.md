## 1. Loading the Tokenizer

To load the tokenizer, we’ll start by creating our `main.py` file and importing the `AutoTokenizer` class from transformers :

`from transformers import AutoTokenizer`

The `AutoTokenizer` is a special class provided by the transformers package:
1. allows you to load any supported model’s tokenizer. 
2. You can use model-specific tokenizer classes, but this class makes it easier to switch between `tokenizers` as needed.

Now that we have the import set up, we can load the tokenizer by passing in the directory that all of our files from earlier were downloaded to:

## 2. Load the Tokenizer  

```
tokenizer_path = "/home/user/data/llama-2-tokenizer"
tokenizer = AutoTokenizer.from_pretrained(tokenizer_path)
```

Great! We now have the Tokenizer loaded… 

### **but what does it do?**

Well, at its core, the tokenizer is responsible for taking in a natural language sentence like:

`‘Python is my favorite language!’ `
and converting it to a sequence of what are called `tokens`. 

A token in LLM terms is simply a given word, phrase, letter, or symbol that corresponds to a specified number, otherwise known as a token ID. For example, the word `‘Python’` is a token that corresponds to the token ID 5132. This mapping is described via the tokenizer’s vocabulary. 

The vocabulary simply maps each word, phrase, letter, or symbol to its corresponding token ID. If you search for ‘Python’ in the tokenizer.json file, you’ll see the following line:

`"▁Python": 5132,`

Now, what’s important to note is that Llama2’s tokenizer has a vocabulary size of **32 thousand**. 

According to the Eton Institute, “Oxford English Dictionary estimates that there are around **170,000 words**” in the English language (Eton Institute, 2023). This doesn’t include company or product names, acronyms, or phrases… so how does the tokenizer convert any given sentence into tokens? Well, this is why there are mappings for individual letters and symbols. Later on, we’ll see how an acronym like 

`‘RHEL’ (RedHat Enterprise Linux) is split into the tokens ‘R’, ‘H’, and ‘EL’, 
`
then those are converted to their corresponding token IDs. Beyond this, the tokenizer also has what’s called an unknown token represented by the symbol 

`<unk>`

,and corresponding to the token ID 0. This `unknown token `can represent anything the tokenizer is unable to convert to a token.

### Why does this all matter? 

Again, it goes back to the input that Llama2 and any other transformer LLM can take in — the values must be numeric. The tokenizer’s primary role is to take in natural language and make it usable by the Llama2 model itself by converting natural language into predefined tokens. During the model’s initial training phase by the company that built the model itself, in this case, Meta, these tokens were used. This means that what the LLM understands is not the word ‘Python’ itself, but that ‘Python’ corresponds to ‘5132’ and when it sees the token ID ‘5132’, similar token IDs like ‘17088’ (Language) might come next.


---

Once we’ve loaded the tokenizer, we can inspect the model and its vocabulary ourselves:

## 1.Constants  

```python
stdout_padding = "#" * 20  

```

## 2.Confirm vocabulary size

```python
print(f"{stdout_padding} Llama2 Tokenizer Details {stdout_padding}\n")  
print(f"Llama2 tokenizer overview: {tokenizer}")  
print(f"Llama2 Vocabulary Size: {len(tokenizer.get_vocab().keys())}\n")  
print(f"{stdout_padding} End of Llama2 Tokenizer Details {stdout_padding}\n")
```

What we’ll see is:

```python
#################### Llama2 Tokenizer Details ####################  
  
Llama2 tokenizer overview: LlamaTokenizerFast(name_or_path='/home/bradley/data/llama-2-tokenizer', vocab_size=32000, model_max_length=1000000000000000019884624838656, is_fast=True, padding_side='right', truncation_side='right', special_tokens={'bos_token': '<s>', 'eos_token': '</s>', 'unk_token': '<unk>'}, clean_up_tokenization_spaces=False),  added_tokens_decoder={  
        0: AddedToken("<unk>", rstrip=False, lstrip=False, single_word=False, normalized=False, special=True),  
        1: AddedToken("<s>", rstrip=False, lstrip=False, single_word=False, normalized=False, special=True),  
        2: AddedToken("</s>", rstrip=False, lstrip=False, single_word=False, normalized=False, special=True),  
}  
Llama2 Vocabulary Size: 32000  
  
#################### End of Llama2 Tokenizer Details ####################
```
