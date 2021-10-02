import React, {useCallback} from 'react';
import {Dimensions, StyleSheet, Text, TouchableOpacity, View} from 'react-native';
import Animated, {
  useAnimatedProps,
  useDerivedValue,
  useSharedValue,
  withTiming,
} from 'react-native-reanimated';
import { ReText } from 'react-native-redash';
import Svg, {Circle} from 'react-native-svg';

const {width, height} = Dimensions.get('window');
const CIRCLE_LENGTH = 1000;
const R = CIRCLE_LENGTH / (2 * Math.PI);
const AnimatedCircle = Animated.createAnimatedComponent(Circle);
const App = () => {
  const progress = useSharedValue(0);
  const animatedProps = useAnimatedProps(() => ({
    strokeDashoffset: CIRCLE_LENGTH * (1 - progress.value),
  }));
  const ProgressText = useDerivedValue(() => {
    return `${Math.floor(progress.value * 100)}`;
  });
  const onPress = useCallback(() =>{
    progress.value = withTiming(progress.value > 0 ? 0 : 1, {duration: 2500});
  }, []);
  return (
    <View style={styles.container}>
    <ReText style={styles.text} text={ProgressText} />
      <Svg style={{position:'absolute'}}>
        <Circle
          cx={width / 2}
          cy={height / 2}
          r={R}
          stroke="#303858"
          strokeWidth={30}
        />
        <AnimatedCircle
          cx={width / 2}
          cy={height / 2}
          r={R}
          stroke="#A6E1FA"
          strokeWidth={15}
          strokeDasharray={CIRCLE_LENGTH}
          animatedProps={animatedProps}
          strokeLinecap={'round'}
        />
      </Svg>
      <TouchableOpacity onPress={onPress} style={styles.button}>
        <Text style={styles.buttonText}>Run</Text>
      </TouchableOpacity>
    </View>
  );
};
export default App;
const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#444B6F',
    justifyContent: 'center',
    alignItems: 'center',
  },
  text: {
    fontSize: 80,
    color: 'rgba(256,256,256,0.7)',
  },
  button: {
    position: 'absolute',
    bottom: 50,
    width: width * 0.7,
    height: 60,
    backgroundColor: '#A6E1FA',
    borderRadius: 25,
    alignItems: 'center',
    justifyContent: 'center',
  },
  buttonText: {
    fontSize: 25,
    color: '#fff',
    letterSpacing: 2.0,
  },
});
