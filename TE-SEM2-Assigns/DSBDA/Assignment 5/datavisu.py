import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


#Reading The Dataset
df = pd.read_csv('/home/hduser/Desktop/Assignment 5/facebook metrics/dataset_Facebook.csv',sep=';')

#Printing 5 Rows Of dataset
print(df.head())

#Describing Dataset
print('=====================================')
print('\tSUMMARY OF DATA')
print('=====================================')

print(df.describe())
print('=====================================')

#Counting And Dropping Null Values
print('=====================================')
print('\tNULL VALUES')
print('=====================================')

print(df.isna().sum())
df = df.dropna()
print('=====================================')



# List Of Null Values
print('=====================================')
print('\tColumns')
print('=====================================')
columns  = list(df.columns.values)
print(columns)
print('=====================================')


# Plotting Histogram of Comments
hist = plt.hist(df['comment'],bins=30)

plt.gcf().canvas.set_window_title('Hoistogram of Comments')
plt.show(hist)

print('=====================================')

hist = plt.scatter(df['Category'],df['like'])
plt.xlabel('category')
plt.ylabel('like')

plt.gcf().canvas.set_window_title('scatter plot of category vs like')
plt.show(hist)

#Plotting Scatter Plot Type vs Comment
hist = plt.scatter(df['Type'],df['comment'])
plt.xlabel('category')
plt.ylabel('comments')

plt.gcf().canvas.set_window_title('scatter plot of Type vs Comments')


plt.show(hist)


#Plotting Scatter Plot Post Month vs Total Interactions
hist = plt.scatter(df['Post Month'],df['Total Interactions'])
plt.xlabel('Post Month')
plt.ylabel('Total Interactions')

plt.gcf().canvas.set_window_title('scatter plot of Post Month vs Total Interactions')


plt.show(hist)


#Plotting Scatter Plot Paid vs Type
hist = plt.scatter(df['Paid'],df['Type'])
plt.xlabel('Paid')
plt.ylabel('Type')

plt.gcf().canvas.set_window_title('scatter plot of Paid vs Type')


plt.show(hist)

#Plotting Scatter Plot Type vs Total Interactions
hist = plt.bar(df['Type'],df['Total Interactions'])
plt.xlabel('Paid')
plt.ylabel('Type')

plt.gcf().canvas.set_window_title('scatter plot of Type vs Total Interaction')


plt.show(hist)
