//
//  MSCollectionViewCalendarLayout.h
//  MSCollectionViewCalendarLayout
//

//! Project version number for MSCollectionViewCalendarLayout.
FOUNDATION_EXPORT double MSCollectionViewCalendarLayoutVersionNumber;

//! Project version string for MSCollectionViewCalendarLayout.
FOUNDATION_EXPORT const unsigned char MSCollectionViewCalendarLayoutVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <MSCollectionViewCalendarLayout/PublicHeader.h>
//
//  MSCollectionViewCalendarLayout.h
//  MSCollectionViewCalendarLayout
//
//  Created by Eric Horacek on 2/18/13.
//  Copyright (c) 2015 Eric Horacek. All rights reserved.
//
//  This code is distributed under the terms and conditions of the MIT license.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

UIKIT_EXTERN NSString * const MSCollectionElementKindTimeRowHeader;
UIKIT_EXTERN NSString * const MSCollectionElementKindDayColumnHeader;
UIKIT_EXTERN NSString * const MSCollectionElementKindTimeRowHeaderBackground;
UIKIT_EXTERN NSString * const MSCollectionElementKindDayColumnHeaderBackground;
UIKIT_EXTERN NSString * const MSCollectionElementKindCurrentTimeIndicator;
UIKIT_EXTERN NSString * const MSCollectionElementKindCurrentTimeHorizontalGridline;
UIKIT_EXTERN NSString * const MSCollectionElementKindVerticalGridline;
UIKIT_EXTERN NSString * const MSCollectionElementKindHorizontalGridline;

typedef NS_ENUM(NSUInteger, MSSectionLayoutType) {
    MSSectionLayoutTypeHorizontalTile,
    MSSectionLayoutTypeVerticalTile
};

typedef NS_ENUM(NSUInteger, MSHeaderLayoutType) {
    MSHeaderLayoutTypeTimeRowAboveDayColumn,
    MSHeaderLayoutTypeDayColumnAboveTimeRow
};

@class MSCollectionViewCalendarLayout;
@protocol MSCollectionViewDelegateCalendarLayout;

@interface MSCollectionViewCalendarLayout : UICollectionViewLayout

@property (nonatomic, weak) id <MSCollectionViewDelegateCalendarLayout> delegate;

@property (nonatomic) CGFloat sectionWidth;
@property (nonatomic) CGFloat hourHeight;
@property (nonatomic) CGFloat dayColumnHeaderHeight;
@property (nonatomic) CGFloat timeRowHeaderWidth;
@property (nonatomic) CGSize currentTimeIndicatorSize;
@property (nonatomic) CGFloat horizontalGridlineHeight;
@property (nonatomic) CGFloat verticalGridlineWidth;
@property (nonatomic) CGFloat currentTimeHorizontalGridlineHeight;
@property (nonatomic) UIEdgeInsets sectionMargin;
@property (nonatomic) UIEdgeInsets contentMargin;
@property (nonatomic) UIEdgeInsets cellMargin;
@property (nonatomic) MSSectionLayoutType sectionLayoutType;
@property (nonatomic) MSHeaderLayoutType headerLayoutType;
@property (nonatomic) BOOL displayHeaderBackgroundAtOrigin;
@property (nonatomic) BOOL shortenDayHoursAccordingToEventsCount;

- (NSDate *)dateForTimeRowHeaderAtIndexPath:(NSIndexPath *)indexPath;
- (NSDate *)dateForDayColumnHeaderAtIndexPath:(NSIndexPath *)indexPath;

- (void)scrollToSection:(NSInteger)section animated:(BOOL)animated;
- (void)scrollCollectionViewToClosestSectionToCurrentTimeAnimated:(BOOL)animated;

// Since a "reloadData" on the UICollectionView doesn't call "prepareForCollectionViewUpdates:", this method must be called first to flush the internal caches
- (void)invalidateLayoutCache;

@end

@protocol MSCollectionViewDelegateCalendarLayout <UICollectionViewDelegate>

@required

- (NSDate *)collectionView:(UICollectionView *)collectionView layout:(MSCollectionViewCalendarLayout *)collectionViewLayout dayForSection:(NSInteger)section;
- (NSDate *)collectionView:(UICollectionView *)collectionView layout:(MSCollectionViewCalendarLayout *)collectionViewLayout startTimeForItemAtIndexPath:(NSIndexPath *)indexPath;
- (NSDate *)collectionView:(UICollectionView *)collectionView layout:(MSCollectionViewCalendarLayout *)collectionViewLayout endTimeForItemAtIndexPath:(NSIndexPath *)indexPath;
- (NSDate *)currentTimeComponentsForCollectionView:(UICollectionView *)collectionView layout:(MSCollectionViewCalendarLayout *)collectionViewLayout;

@end

