import React, {useState} from 'react';
import {View, Text, Image, TouchableOpacity, StyleSheet} from 'react-native';
import DiceOne from './assets/dice1.png';
import DiceThree from './assets/dice2.png';
import DiceTwo from './assets/dice3.png';
import DiceFour from './assets/dice4.png';
import DiceFive from './assets/dice5.png';
import DiceSix from './assets/dice6.png';
const App = () => {
  const [image, setImage] = useState(DiceOne);
  const [image1, setImage1] = useState(DiceTwo);
  const click = () => {
    let randomNumber = Math.floor(Math.random() * 6) + 1;
    let randomNumber2 = Math.floor(Math.random() * 6) + 1;
    switch (randomNumber) {
      case 1:
        setImage(DiceOne);
        break;
      case 2:
        setImage(DiceTwo);
        break;
      case 3:
        setImage(DiceThree);
        break;
      case 4:
        setImage(DiceFour);
        break;
      case 5:
        setImage(DiceFive);
        break;
      case 6:
        setImage(DiceSix);
        break;
      default:
        setImage(DiceOne);
        break;
    }
    switch (randomNumber2) {
      case 1:
        setImage1(DiceOne);
        break;
      case 2:
        setImage1(DiceTwo);
        break;
      case 3:
        setImage1(DiceThree);
        break;
      case 4:
        setImage1(DiceFour);
        break;
      case 5:
        setImage1(DiceFive);
        break;
      case 6:
        setImage1(DiceSix);
        break;
      default:
        setImage1(DiceOne);
        break;
    }
  };
  return (
    <>
      <View style={styles.container}>
        <TouchableOpacity onPress={click}>
          <Image source={image} style={styles.images} />
          <Image source={image1} style={styles.images2} />
        </TouchableOpacity>
      </View>
    </>
  );
};

export default App;

const styles = StyleSheet.create({
  container: {
    backgroundColor: '#Ff69b4',
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  images: {
    width: 200,
    height: 200,
  },
  images2: {
    width: 200,
    height: 200,
  },
  // clickme: {
  //   marginTop: 20,
  //   color: '#ffffff',
  //   fontWeight: 'bold',
  //   fontSize: 20,
  //   backgroundColor: '#000000',
  //   borderRadius: 5,
  //   paddingHorizontal: 40,
  //   paddingVertical: 10,
  //   borderWidth: 2,
  //   borderColor: '#30475E',
  // },
})