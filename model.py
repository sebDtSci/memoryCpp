import torch
from transformers import BartForConditionalGeneration

model = BartForConditionalGeneration.from_pretrained('facebook/bart-large-cnn')
scripted_model = torch.jit.script(model)
scripted_model.save("bart_model.pt")