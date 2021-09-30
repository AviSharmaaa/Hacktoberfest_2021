import pyttsx3 as t2s
import PyPDF2 as reader

inp = input('Enter PDF Name: ')
book = open(inp + '.pdf' , 'rb')
pdf = reader.PdfFileReader(book)
pages = pdf.numPages

print('No. of pages: ' + str(pages))
start = int(input('Enter Page number to start: '))
engine = t2s.init()
engine.setProperty("rate", 160)
# voices = engine.getProperty('voices')
# engine.setProperty('voice', voices[1].id)

for num in range(start-1, pages):
    page = pdf.getPage(num)
    text = page.extractText()
    engine.say(text)
    engine.runAndWait()