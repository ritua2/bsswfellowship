import os
import tensorflow as tf
from tensorflow import keras

mnist = tf.keras.datasets.mnist

(x_train, y_train), (x_test, y_test) = mnist.load_data()
#normalize the data
x_train = x_train / 255.0
x_test = x_test/ 255.0

# Model / data parameters
num_classes = 10
input_shape = (28, 28, 1)

filename = "testmodel2.h5"

# check if checkpoint file exists. if does, load the model and skip building the model
if (os.path.isfile(filename)):
    print("Restarting")
    model = tf.keras.models.load_model(filename)
else:
    print('Building the model from beginning')
    model = tf.keras.models.Sequential([
        keras.Input(shape=input_shape),
        tf.keras.layers.Conv2D(32, kernel_size=(3, 3), activation="relu"),
        tf.keras.layers.MaxPooling2D(pool_size=(2, 2)),
        tf.keras.layers.Conv2D(64, kernel_size=(3, 3), activation="relu"),
        tf.keras.layers.MaxPooling2D(pool_size=(2, 2)),
        tf.keras.layers.Flatten(),
        tf.keras.layers.Dropout(0.5),
        tf.keras.layers.Dense(num_classes, activation="softmax"),
    ])
    model.summary()
    model.compile(optimizer='adam',
                  loss='sparse_categorical_crossentropy',
                  metrics=['accuracy'])

checkpoint_callback = tf.keras.callbacks.ModelCheckpoint(filename, monitor='val_loss', verbose=1, save_best_only=True, mode='min', save_freq="epoch")

model.fit(x_train, y_train, epochs=5, batch_size = 100, validation_split = 0.1, callbacks=[checkpoint_callback])

totalScore=model.evaluate(x_test, y_test, verbose=2)
print("Test loss:", totalScore[0])
print("Test accuracy:", totalScore[1])

# Create a basic model instance again for comparison purposes
model = tf.keras.models.Sequential([
        keras.Input(shape=input_shape),
        tf.keras.layers.Conv2D(32, kernel_size=(3, 3), activation="relu"),
        tf.keras.layers.MaxPooling2D(pool_size=(2, 2)),
        tf.keras.layers.Conv2D(64, kernel_size=(3, 3), activation="relu"),
        tf.keras.layers.MaxPooling2D(pool_size=(2, 2)),
        tf.keras.layers.Flatten(),
        tf.keras.layers.Dropout(0.5),
        tf.keras.layers.Dense(num_classes, activation="softmax"),
    ])
model.compile(optimizer='adam',
                  loss='sparse_categorical_crossentropy',
                  metrics=['accuracy'])

# Evaluate the recreated model 
totalScore= model.evaluate(x_test, y_test, verbose=2)
print("Untrained model, accuracy: {:5.2f}%".format(100 * totalScore[1]))
model.summary()

# Now loads the weights from the saved checkpoint
model.load_weights('testmodel2.h5')

# Re-evaluate the model and compare its output with the previous untrained model run
testScore = model.evaluate(x_test, y_test, verbose=2)
print("Restored model, accuracy: {:5.2f}%".format(100 * testScore[1]))
