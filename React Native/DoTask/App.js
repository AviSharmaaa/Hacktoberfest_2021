import React, {useState, useRef} from 'react';
import {
  Keyboard,
  KeyboardAvoidingView,
  Platform,
  ScrollView,
  StyleSheet,
  Text,
  TextInput,
  TouchableOpacity,
  View,
} from 'react-native';
import Todo from './components/Todo';
import LottieView from 'lottie-react-native';
import AsyncStorage from '@react-native-async-storage/async-storage';
const App = () => {
  const [task, setTask] = useState();
  const [taskItem, setTaskItem] = useState([]);
  const buttonRef = useRef(null);
  React.useEffect(() => {
    getTodos();
  }, []);
  React.useEffect(() => {
    saveTodo(taskItem);
  }, [taskItem]);
  const handleAddTask = () => {
    buttonRef.current?.play(0, 75);
    Keyboard.dismiss();
    setTaskItem([...taskItem, task]);
    setTask(null);
  };
  const completeTask = index => {
    let itemCopy = [...taskItem];
    itemCopy.splice(index, 1);
    setTaskItem(itemCopy);
  };
  const saveTodo = async taskItem => {
    try {
      const stringifyTask = JSON.stringify(taskItem);
      await AsyncStorage.setItem('taskItem', stringifyTask);
    } catch (error) {
      console.log(error);
    }
  };
  const getTodos = async () => {
    try {
      const taskItem = await AsyncStorage.getItem('taskItem');
      if (taskItem != null) {
        setTaskItem(JSON.parse(taskItem));
      }
    } catch (error) {
      console.log(error);
    }
  };
  return (
    <View style={{flex: 1, backgroundColor: '#E8EAED'}}>
      {taskItem.length > 0 ? (
        <>
          <ScrollView style={styles.container}>
            <View style={styles.taskWrapper}>
              <Text style={styles.text}>Today's Task</Text>
              <Text style={{fontWeight: 'bold', paddingHorizontal: 6}}>
                Total task remaining: {taskItem.length}
              </Text>
              <View style={styles.item}>
                {taskItem.map((item, index) => {
                  return (
                    <TouchableOpacity
                      key={index}
                      onPress={() => completeTask(index)}>
                      <Todo key={index} text={item} />
                    </TouchableOpacity>
                  );
                })}
              </View>
            </View>
          </ScrollView>
        </>
      ) : (
        <View style={{flex: 1, alignItems: 'center', justifyContent: 'center'}}>
          <LottieView
            source={require('./assets/yoga.json')}
            style={{width: '100%', aspectRatio: 1}}
            position={'absolute'}
            autoPlay
            loop
          />
          <Text style={{fontWeight: 'bold', fontSize: 20}}>Add new task +</Text>
        </View>
      )}
      <View>
        <KeyboardAvoidingView
          behavior={Platform.OS === 'ios' ? 'padding' : 'height'}
          style={styles.writeWrapper}>
          <TextInput
            style={styles.input}
            placeholder={'Write a task'}
            value={task}
            onChangeText={text => setTask(text)}
            color={'#000'}
            placeholderTextColor={'#C0C0C0'}
          />
          <TouchableOpacity onPress={() => handleAddTask()}>
            <LottieView
              ref={buttonRef}
              source={require('./assets/addButton.json')}
              style={{width: 50, height: 50}}
              autoPlay={false}
              loop={false}
              speed={2}
            />
          </TouchableOpacity>
        </KeyboardAvoidingView>
      </View>
    </View>
  );
};
const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#E8EAED',
    height: '70%',
    width: '100%',
    marginBottom: 80,
  },
  taskWrapper: {
    paddingTop: 20,
    paddingHorizontal: 15,
  },
  text: {
    fontSize: 25,
    fontWeight: 'bold',
  },
  item: {
    marginTop: 10,
  },
  addWrapper: {
    height: 60,
    width: 60,
    borderRadius: 60,
    backgroundColor: '#fff',
    justifyContent: 'center',
    alignItems: 'center',
    borderColor: '#C0C0C0',
    borderWidth: 1,
  },
  addText: {},
  writeWrapper: {
    position: 'absolute',
    bottom: 25,
    flexDirection: 'row',
    width: '100%',
    justifyContent: 'space-around',
    alignItems: 'center',
  },
  input: {
    paddingVertical: 10,
    width: 250,
    paddingHorizontal: 10,
    backgroundColor: '#fff',
    borderRadius: 60,
    borderColor: '#C0C0C0',
    borderWidth: 1,
  },
});

export default App;
