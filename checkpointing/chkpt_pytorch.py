import torch
from torchvision import datasets
from torchvision.transforms import ToTensor
import torch.optim as optim
import matplotlib.pyplot as plt
from torch.autograd import Variable
import torch.nn as nn

traindata = datasets.MNIST(
    root = 'data',
    train = True,                         
    transform = ToTensor(), 
    download = True,            
)
testdata = datasets.MNIST(
    root = 'data', 
    train = False, 
    transform = ToTensor()
)


trainloader = torch.utils.data.DataLoader(traindata, batch_size=100, shuffle=True, num_workers=2)

testloader = torch.utils.data.DataLoader(testdata, batch_size=100, shuffle=False, num_workers=2)

class cnn(nn.Module):
    def __init__(self):
        super(cnn, self).__init__()
        self.conv = nn.Sequential(         
            nn.Conv2d(
                in_channels=1,              
                out_channels=16,            
                kernel_size=5,              
                stride=1,                   
                padding=2,                  
            ),                              
            nn.ReLU(),                      
            nn.MaxPool2d(kernel_size=2),    
        )
        self.conv2 = nn.Sequential(         
            nn.Conv2d(16, 32, 5, 1, 2),     
            nn.ReLU(),                      
            nn.MaxPool2d(2),                
        )
        self.out = nn.Linear(32 * 7 * 7, 10)
    def forward(self, a):
        a = self.conv(a)
        a = self.conv2(a)
        a = a.view(a.size(0), -1)       
        outp = self.out(a)
        return outp, a 

model = cnn()

lossFct = nn.CrossEntropyLoss() 

optimizer = optim.Adam(model.parameters(), lr = 0.001)   

PATH = "chkptnew.out"
num_epochs = 1
loss = 0.2
def train(num_epochs, model, loaders):
    
    model.train()
        
    # Train the model
    total_step = len(trainloader)
        
    for epoch in range(num_epochs):
        for i, (images, labels) in enumerate(trainloader):
            
            b_x = Variable(images)   # batch x
            b_y = Variable(labels)   # batch y
            output = model(b_x)[0]               
            loss = lossFct(output, b_y)
            
            # clear gradients for this training step   
            optimizer.zero_grad()           
            
            # backpropagation, compute gradients 
            loss.backward()    
            # apply gradients             
            optimizer.step()                
            
            if (i+1) % 100 == 0:
                print ('Epoch [{}/{}], Step [{}/{}], Loss: {:.4f}' 
                       .format(epoch + 1, num_epochs, i + 1, total_step, loss.item()))
            pass
        
        pass
    
    
    pass
train(num_epochs, model, trainloader)


torch.save({
            'epoch': num_epochs,
            'model_state_dict': model.state_dict(),
            'optimizer_state_dict': optimizer.state_dict(),
            'loss': loss,
            }, PATH)

model2 = cnn()
optimizer = optim.Adam(model2.parameters(), lr = 0.001)  

checkpoint = torch.load(PATH)
model2.load_state_dict(checkpoint['model_state_dict'])
optimizer.load_state_dict(checkpoint['optimizer_state_dict'])
epoch = checkpoint['epoch']
loss = checkpoint['loss']

print('Parameters loaded in model2')
print(model2)
print(epoch)
print(loss)

#continue working with model2 as needed

def test():
    # Test the model
    model2.eval()
    with torch.no_grad():
        correct = 0
        total = 0
        i=0
        for images, labels in testloader:
            test_output, last_layer = model2(images)
            pred_y = torch.max(test_output, 1)[1].data.squeeze()
            accuracy = (pred_y == labels).sum().item() / float(labels.size(0))
            if(i < 20) :
              plt.imshow(images[i].squeeze(), cmap='gray')
              #plt.title('%i' % labels[i])
              #plt.title ('%i' % pred_y[i])
              plt.show()
              print(f'Predicted number in the image   : {pred_y[i]}')
              print(f'Actual number as per image label: {labels[i]}')
              
            i = i+1
        pass
        print('Test Accuracy of the model on the 10000 test images: %.2f' % accuracy)
    pass

test()
